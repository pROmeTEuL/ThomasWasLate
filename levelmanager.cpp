#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>

#include "levelmanager.h"
#include "textureholder.h"

LevelManager::LevelManager()
{

}

float LevelManager::getTimeLimit()
{
    return m_BaseTimeLimit * m_TimeModifier;
}

Vector2f LevelManager::getStartPosition()
{
    return m_StartPosition;
}

int **LevelManager::nextLevel(VertexArray &rVaLevel)
{
    m_LevelSize.x = 0;
    m_LevelSize.y = 0;
    ++m_CurrentLevel;
    if (m_CurrentLevel > NUM_LEVELS) {
        m_CurrentLevel = 1;
        m_TimeModifier -= .1f;
    }
    string levelToLoad;
    switch (m_CurrentLevel) {
    case 1:
        levelToLoad = "levels/level1.txt";
        m_StartPosition.x = 100;
        m_StartPosition.y = 100;
        m_BaseTimeLimit = 30.0f;
        break;
    case 2:
        levelToLoad = "levels/level2.txt";
        m_StartPosition.x = 100;
        m_StartPosition.y = 3600;
        m_BaseTimeLimit = 100.0f;
        break;
    case 3:
        levelToLoad = "levels/level3.txt";
        m_StartPosition.x = 1250;
        m_StartPosition.y = 0;
        m_BaseTimeLimit = 30.0f;
        break;
    case 4:
        levelToLoad = "levels/level4.txt";
        m_StartPosition.x = 50;
        m_StartPosition.y = 200;
        m_BaseTimeLimit = 100.0f;
        break;
    }
    ifstream inputFile(levelToLoad);
    string s;
    while (getline(inputFile, s)) {
        ++m_LevelSize.y;
        m_LevelSize.x = std::max<int>(m_LevelSize.x, s.length());
    }
    inputFile.clear();
    inputFile.seekg(0, ios::beg);
    int** arrayLevel = new int*[m_LevelSize.y];
    for (int i = 0; i < m_LevelSize.y; ++i)
        arrayLevel[i] = new int[m_LevelSize.x];
    string row;
    int y = 0;
    while (inputFile >> row) {
        for (int x = 0; x < row.length(); ++x) {
            const char val = row[x];
            arrayLevel[y][x] = val - '0';
        }
        ++y;
    }
    inputFile.close();
    rVaLevel.setPrimitiveType(Quads);
    rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);
    int currentVertex = 0;
    for (int x = 0; x < m_LevelSize.x; ++x)
        for (int y = 0; y < m_LevelSize.y; ++y) {
            rVaLevel[currentVertex + 0].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE);
            rVaLevel[currentVertex + 1].position = Vector2f(x * TILE_SIZE + TILE_SIZE, y * TILE_SIZE);
            rVaLevel[currentVertex + 2].position = Vector2f(x * TILE_SIZE + TILE_SIZE, y * TILE_SIZE + TILE_SIZE);
            rVaLevel[currentVertex + 3].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE + TILE_SIZE);
            int verticalOffset = arrayLevel[y][x] * TILE_SIZE;
            rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
            rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
            rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
            rVaLevel[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
            currentVertex += VERTS_IN_QUAD;
        }
    return arrayLevel;
}

Vector2i LevelManager::getLevelSize()
{
    return m_LevelSize;
}

int LevelManager::getCurrentLevel()
{
    return m_CurrentLevel;
}
