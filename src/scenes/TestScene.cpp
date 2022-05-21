#include "TestScene.h"

namespace LightInDarkness
{
    TestScene::TestScene(){

    }
    TestScene::~TestScene()
    {
    }

    void TestScene::OnInit(){
        Renderer::Initialize();
        GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        glCreateBuffers(1, &IBO);

        VertexBuffer testBuffer{vertices,sizeof(vertices)};


        glNamedBufferStorage(IBO, sizeof(indices), indices, GL_DYNAMIC_STORAGE_BIT);

        vertexArrayObj.AddBuffer<VertexBuffer>(testBuffer);

        glVertexArrayElementBuffer(vertexArrayObj.GetID(), IBO);

    }
    void TestScene::OnEvent(){

    }
    void TestScene::OnUpdate(float dt){



        Renderer::Clear(glm::vec4(0.831, 0.047, 0.047, 1.0f));

        glUseProgram(shaderProgram);
        vertexArrayObj.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT, 0);
    }
    void TestScene::OnShutdown(){
        Renderer::Shutdown();
    }
} 

