#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

const unsigned static int WIDTH = 1080;
const unsigned static int HEIGHT = 720;

const static float dt = 1.f / 60.f;

template <typename T>
T mapValue(T value, T inMin, T inMax, T outMin, T outMax) {
    return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}

#endif