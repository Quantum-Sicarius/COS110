
class Animal {
protected:
  char const *name;

public:
  Animal(char const *name_);
  virtual char const *action() = 0;
  virtual void detectHuman();
};

class Bird : public Animal {
public:
  Bird(char const *name_);
  virtual char const *action();
};

class TameAnimal : public Animal {
public:
  TameAnimal(char const *name_);
  virtual void detectHuman();
  virtual char const *action() = 0;
};

class Dog : public TameAnimal {
public:
  Dog(char const *name_);
  virtual char const *action();
};

class Cat : public TameAnimal {
public:
  Cat(char const *name_);
  virtual char const *action();
};
