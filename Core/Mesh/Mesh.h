#pragma once
#include <memory>
#include "Collision/Collision.h"
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "../Shader/Buffers/Buffers.h"

class Pickup;

struct Vertex
{
    glm::vec3 Pos;
    glm::vec3 Color;
    glm::vec3 Normal = glm::vec3(0.f);
    Vertex(glm::vec3 Pos, glm::vec3 rgb) : Pos(Pos), Color(rgb)
    {
    }
};

struct Triangles
{
    unsigned int a, b, c;
    Triangles(unsigned int a, unsigned int b, unsigned int c) : a(a), b(b), c(c)
    {
    }
};

class Cube;

class Mesh
{
    int count = 0;

public:
    std::vector<Vertex> mVertices;
    std::vector<GLuint> mIndices;
    std::vector<Triangles> tIndices;
    std::vector<std::shared_ptr<Cube>> Package;

	bool isTarrain = false;
    bool isLine = false;

     float xy(float t, float u);
	void CreateTerrain(float xStart, float yStart, float xEnd, float yEnd, float Step);

    void Draw();

    bool FindTerrainHeight(Mesh& Ref, glm::vec3& Player);

    void BindBuffers();

    float f(float x);
    void CreateCurve(Mesh ThePlane);

    unsigned int VAO;
private:

    unsigned int VBO;
    unsigned int EBO;
};


class Cube{
    int index = 0;
    glm::vec3 Position;
    glm::vec3 Scale;
    glm::vec3 Rotation;

public:
    Cube()
    {
    }
    bool bIsPlayer = false;
    bool bCanInteract = false;
    bool bIsPickup = false;
    bool bShouldRender = true;
    bool bIsDoor = false;
    bool bDoorInteracted = false;
    

    Cube* OverlappedCube = nullptr;

    void CreateCube(glm::vec3 position, glm::vec3 scale, glm::vec3 color, bool isPickup = false, bool isPlayer = false, glm::vec3 rotation = glm::vec3(0.f), bool isDoor = false);
    void Draw();

    std::shared_ptr<Collision> Collider;
    glm::vec3& GetPosition() { return Position; }
    glm::vec3& GetScale() { return Scale; }
    glm::vec3& GetRotation() { return Rotation; }
    int& GetIndex() { return index; }
    void AddCollider(glm::vec3 scale,ECollisionType collisionType, glm::vec3 offset = glm::vec3(0.f));
    virtual ~Cube();

    void BindBuffers();

	unsigned int VAO;
private:
    
    unsigned int VBO;
    unsigned int EBO;

    std::vector<Vertex> cVertices;
    std::vector<Triangles> cIndices;
    void init();

};


