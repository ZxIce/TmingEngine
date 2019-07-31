#pragma once
//
////= INCLUDES ==================
//#include "im.h"
//#include <string>
//#include "../Core/EngineDefs.h"
//#include "MathHelper.h"
//#include "stdio.h"
////=============================
//
//namespace TmingEngine::Math
//{
//    class ENGINE_CLASS Vector3
//    {
//    public:
//        // Constructor
//        Vector3()
//        {
//            x = 0;
//            y = 0;
//            z = 0;
//        }
//
//        // Copy-constructor
//        Vector3(const Vector3& vector)
//        {
//            x = vector.x;
//            y = vector.y;
//            z = vector.z;
//        }
//
//        // Construct from coordinates.
//        Vector3(float x, float y, float z)
//        {
//            this->x = x;
//            this->y = y;
//            this->z = z;
//        }
//
//        // Construct from single value.
//        Vector3(float f)
//        {
//            x = f;
//            y = f;
//            z = f;
//        }
//
//        //= NORMALIZATION ========================================================================================
//        Vector3 Normalized() const
//        {
//            float factor = Length();
//            factor = 1.0f / factor;
//            return Vector3(x * factor, y * factor, z * factor);
//        }
//
//        void Normalize()
//        {
//            float factor = Length();
//            factor = 1.0f / factor;
//            x *= factor;
//            y *= factor;
//            z *= factor;
//        };
//        static Vector3 Normalize(const Vector3& v) { return v.Normalized(); }
//        //========================================================================================================
//
//        //= DOT PRODUCT ==========================================================================================
//        static float Dot(const Vector3& v1, const Vector3& v2) { return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z); }
//        float Dot(const Vector3& rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }
//        //========================================================================================================
//
//        //= CROSS PRODUCT ========================================================================================
//        static Vector3 Cross(const Vector3& v1, const Vector3& v2)
//        {
//            float x = v1.y * v2.z - v2.y * v1.z;
//            float y = -(v1.x * v2.z - v2.x * v1.z);
//            float z = v1.x * v2.y - v2.x * v1.y;
//
//            return Vector3(x, y, z);
//        }
//        Vector3 Cross(const Vector3& v2) const { return Cross(*this, v2); }
//        //========================================================================================================
//
//        //= LENGTH ===============================================================================================
//        static float Length(const Vector3& v1, const Vector3& v2)
//        {
//            return Sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z));
//        }
//
//        static float LengthSquared(const Vector3& v1, const Vector3& v2)
//        {
//            return (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y) + (v1.z - v2.z) * (v1.z - v2.z);
//        }
//
//        float Length() const { return Sqrt(x * x + y * y + z * z); }
//        float LengthSquared() const { return x * x + y * y + z * z; }
//        //========================================================================================================
//
//        //= MISC =================================================================================================
//        void Floor()
//        {
//            x = floorf(x);
//            y = floorf(y);
//            z = floorf(z);
//        }
//        Vector3 Absolute() const { return Vector3(abs(x), abs(y), abs(z)); }
//        float Volume() const { return x * y * z; }
//        //========================================================================================================
//
//        //= MULTIPLICATION =======================================================================================
//        Vector3 operator*(const Vector3& b) const
//        {
//            return Vector3(
//                x * b.x,
//                y * b.y,
//                z * b.z
//            );
//        }
//
//        void operator*=(const Vector3& b)
//        {
//            x *= b.x;
//            y *= b.y;
//            z *= b.z;
//        }
//
//        Vector3 operator*(const float value) const
//        {
//            return Vector3(
//                x * value,
//                y * value,
//                z * value
//            );
//        }
//
//        void operator*=(const float value)
//        {
//            x *= value;
//            y *= value;
//            z *= value;
//        }
//
//        //=======================================================================================================
//
//        //= ADDITION ============================================================================================
//        Vector3 operator+(const Vector3& b) const { return Vector3(x + b.x, y + b.y, z + b.z); }
//        Vector3 operator+(const float value) const { return Vector3(x + value, y + value, z + value); }
//
//        void operator+=(const Vector3& b)
//        {
//            x += b.x;
//            y += b.y;
//            z += b.z;
//        }
//
//        void operator+=(const float value)
//        {
//            x += value;
//            y += value;
//            z += value;
//        }
//        //======================================================================================================
//
//        //= SUBTRACTION ========================================================================================
//        Vector3 operator-(const Vector3& b) const { return Vector3(x - b.x, y - b.y, z - b.z); }
//        Vector3 operator-(const float value) { return Vector3(x - value, y - value, z - value); }
//
//        void operator-=(const Vector3& rhs)
//        {
//            x -= rhs.x;
//            y -= rhs.y;
//            z -= rhs.z;
//        }
//        //=======================================================================================================
//
//        //= DIVISION ============================================================================================
//        Vector3 operator/(const Vector3& rhs) const { return Vector3(x / rhs.x, y / rhs.y, z / rhs.z); }
//        Vector3 operator/(const float rhs) { return Vector3(x / rhs, y / rhs, z / rhs); }
//
//        void operator/=(const Vector3& rhs)
//        {
//            x /= rhs.x;
//            y /= rhs.y;
//            z /= rhs.z;
//        }
//        //========================================================================================================
//
//        //= COMPARISON ===========================================================================================
//        bool operator==(const Vector3& rhs) const
//        {
//            return x == rhs.x && y == rhs.y && z == rhs.z;
//        }
//
//        bool operator!=(const Vector3& rhs) const
//        {
//            return !(*this == rhs);
//        }
//        //========================================================================================================
//
//        std::string ToString() const;
//
//        float x;
//        float y;
//        float z;
//
//        static const Vector3 Zero;
//        static const Vector3 Left;
//        static const Vector3 Right;
//        static const Vector3 Up;
//        static const Vector3 Down;
//        static const Vector3 Forward;
//        static const Vector3 Back;
//        static const Vector3 One;
//        static const Vector3 Infinity;
//        static const Vector3 InfinityNeg;
//        
//        glm::vec3<float> toVec3()
//        {
//            new glm::vec3(x,y,z);
//        }
//        
//    };
//
//    // Reverse order operators
//    inline ENGINE_CLASS Vector3 operator*(float lhs, const Vector3& rhs) { return rhs * lhs; }
//}


#include "../Core/EngineDefs.h"
#include <string>
#include <math.h>

namespace TmingEngine {
    ENGINE_CLASS class Vector3
    {
        
    public:
        float x;
        float y;
        float z;
        
        Vector3()
        {
            x=0;
            y=0;
            z=0;
        }
        
        Vector3(float x, float y,float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
                static const Vector3 Zero;
                static const Vector3 Left;
                static const Vector3 Right;
                static const Vector3 Up;
                static const Vector3 Down;
                static const Vector3 Forward;
                static const Vector3 Back;
                static const Vector3 One;
                static const Vector3 Infinity;
                static const Vector3 InfinityNeg;
        std::string ToString() const;
        
        bool operator==(const Vector3 & other) const
        {
            return x == other.x && y == other.y && z == other.z;
        }
        
        Vector3 operator+(const Vector3 & other)const
        {
            return Vector3(x+other.x, y + other.y,z + other.z);
        }
        
        void operator+=(const Vector3 & other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
        }
        
        Vector3 operator-(const Vector3 & other)const
        {
            return Vector3(x - other.x, y - other.y,z - other.z);
        }
        
        void operator-=(const Vector3 & other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
        }
        
        static Vector3 Cross(const Vector3& v1, const Vector3& v2)
        {
            float x = v1.y * v2.z - v2.y * v1.z;
            float y = -(v1.x * v2.z - v2.x * v1.z);
            float z = v1.x * v2.y - v2.x * v1.y;
            return Vector3(x, y, z);
        }
        
        static Vector3 Normalize(const Vector3& v )
        {
            float len = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
            return Vector3(v.x/len , v.y / len , v.y / len);
        }
        
        Vector3 operator*(const float other)const
        {
            return Vector3(x * other, y * other ,z * other);
        }
        
        
    };
}
