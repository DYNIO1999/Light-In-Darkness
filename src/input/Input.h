#ifndef _SRC_INPUT_INPUT_H_
#define _SRC_INPUT_INPUT_H_
#include <utility>
namespace LightInDarkness
{
    class Input
    {
    public:
        static bool IsKeyPressed(int keycode);
        static bool IsMouseButtonPressed(int button);
        static float GetMouseX();
        static float GetMouseY();
        static std::pair<float, float> GetMousePosition();
    };    
} 
#endif