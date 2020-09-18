cmake_minimum_required (VERSION 3.10)

project (RayTracer VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set ( SOURCE_FILES
  source/Main.cpp
  source/Camera.cpp
  source/geometry/HittableList.cpp
  source/geometry/Ray.cpp
  source/geometry/Sphere.cpp
  source/geometry/Vector3.cpp
  source/materials/Dielectric.cpp
  source/materials/Lambertian.cpp
  source/materials/Metal.cpp
)

set ( INCLUDE_FILES
  include/geometry/Hittable.h
  include/geometry/HittableList.h
  include/geometry/Ray.h
  include/geometry/Sphere.h
  include/geometry/Vector3.h
  include/materials/Dielectric.h
  include/materials/Lambertian.h
  include/materials/Material.h
  include/materials/Metal.h
  include/utilities/ColorUtils.h
  include/utilities/MathUtils.h
  include/Camera.h
)


add_executable(RayTracer ${SOURCE_FILES} ${INCLUDE_FILES})

include_directories(include)