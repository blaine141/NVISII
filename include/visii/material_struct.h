/* File shared by both host and device */
#pragma once

#define MAX_MATERIALS 100000
#include <stdint.h>
#include <glm/glm.hpp>
using namespace glm;

/* Follows the disney BSDF */
struct MaterialStruct {
    vec4 base_color = vec4(0.f); // 16 // Note: also contains alpha
    vec4 subsurface_radius = vec4(0.f); // 32
    vec4 subsurface_color = vec4(0.f); //48
    
    float subsurface = 0.f; // 52
    float metallic = 0.f; // 56
    float specular = 0.f; // 60
    float specular_tint = 0.f; // 64
    float roughness = 0.f; // 68
    float anisotropic = 0.f; // 72
    float anisotropic_rotation = 0.f; // 76
    float sheen = 0.f; // 80
    float sheen_tint = 0.f; // 84
    float clearcoat = 0.f; // 88
    float clearcoat_roughness = 0.f; // 92
    float ior = 0.f; // 96
    float transmission = 0.f; // 100
    float transmission_roughness = 0.f; // 104
    
    int32_t flags = 0; // 116
    int32_t volume_texture_id = -1; // 108
    int32_t transmission_roughness_texture_id = -1; // 112
    int32_t base_color_texture_id = -1; // 120
    int32_t roughness_texture_id = -1; // 124
    int32_t occlusion_texture_id = -1; // 128


    /* Addresses for texture mapped parameters */
    int32_t alpha_texture_id = -1; // 132
    int32_t normal_map_texture_id = -1; // 136
    int32_t subsurface_color_texture_id = -1; // 140
    int32_t subsurface_radius_texture_id = -1; // 144
    int32_t subsurface_texture_id = -1; // 148
    int32_t metallic_texture_id = -1; // 152
    int32_t specular_texture_id = -1; // 156
    int32_t specular_tint_texture_id = -1; // 160

    int32_t anisotropic_texture_id = -1; // 164
    int32_t anisotropic_rotation_texture_id = -1; // 168
    int32_t sheen_texture_id = -1; // 172
    int32_t sheen_tint_texture_id = -1; // 176
    int32_t clearcoat_texture_id = -1; // 180
    int32_t clearcoat_roughness_texture_id = -1; // 184
    int32_t ior_texture_id = -1; // 188
    int32_t transmission_texture_id = -1; // 192
    // int32_t ph8_id; // 196
    // int32_t ph8_id; // 200
    // int32_t ph8_id; // 184
    // int32_t ph8_id; // 184
};
