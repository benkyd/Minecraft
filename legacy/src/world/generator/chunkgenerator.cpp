#include "../../util/fastnoise.hpp"


void dp() {

    FastNoise noise;
    noise.SetSeed(121212);

    noise.SetNoiseType(FastNoise::SimplexFractal);

    noise.SetFractalOctaves(3);

}

