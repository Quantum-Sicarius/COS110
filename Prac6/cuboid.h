#ifndef CUBOID_H
#define CUBOID_H

template<class c_Type>
class Cuboid {
private:
  c_Type width;
  c_Type height;
  c_Type length;

  public:
    Cuboid(c_Type w, c_Type h, c_Type l) {
      width = w;
      height = h;
      length = l;
    }
    c_Type getVolume() {
      return width * height * length;
    }
    c_Type getSurfaceArea() {
      return (2 * ((width * height) + (width * length) + (height * length)));
    }
};

#endif
