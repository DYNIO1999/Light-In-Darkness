#ifndef _SRC_RENDERER_VERTEX_ARRAY_H_
#define _SRC_RENDERER_VERTEX_ARRAY_H_

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

#include <iostream>

namespace LightInDarkness{
class VertexArray
{
public:
    VertexArray();
    ~VertexArray();


    // THINK HOW TO DO IT!!!

    template <typename T, typename K>
    void AddBuffer(T &_buffer, K &_layout);
    template <typename T>
    void AddBuffer(const T &_buffer);
    template <>
    void AddBuffer<VertexBuffer>(VertexBuffer&_buffer, VertexBufferLayout& _layout){
        //STRIDE AND STUFF THINK !!!
        //std::cout<<"SIZE:"<<_layout.GetSize() <<'\n';
 
        unsigned int offset =0;
        for (auto& item : _layout)
        {
            glEnableVertexArrayAttrib(m_vertexArrayID, m_attribCounter);
            glVertexArrayAttribFormat(m_vertexArrayID, m_attribCounter, item.count, GL_FLOAT, GL_FALSE, offset*sizeof(float));
            glVertexArrayAttribBinding(m_vertexArrayID, m_attribCounter, 0);
            glVertexArrayVertexBuffer(m_vertexArrayID, 0, _buffer.GetID(), 0, _layout.GetSize()*sizeof(float));
            offset+= item.count;
            ++m_attribCounter;
        }
    }
    template <>
    void AddBuffer<IndexBuffer>(const IndexBuffer &_buffer)
    {
        glVertexArrayElementBuffer(m_vertexArrayID, _buffer.GetID());
    }

    void Bind();
    unsigned int GetID() const { return m_vertexArrayID;}
    const unsigned int AttributeCounter() const {return m_attribCounter;} 
    
private:
    unsigned int m_vertexArrayID;
    unsigned int m_attribCounter;

};
}
#endif