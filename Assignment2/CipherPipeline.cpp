#include "CipherPipeline.h"
#include <iostream>

std::string CipherPipeline::encode(std::string s) {
  std::string result = s;

  for (size_t i = 0; i < this->pipeline.size(); i++) {
    result = (this->pipeline[i])->encode(result);
  }

  return result;
}
std::string CipherPipeline::decode(std::string s) {
  std::string result = s;
  for (size_t i = this->pipeline.size(); i--;) {
    result = (this->pipeline[i])->decode(result);
  }

  return result;
}

CipherPipeline &CipherPipeline::operator+=(Cipher *c) {
  this->pipeline.push_back(c);
  return *this;
}
CipherPipeline &CipherPipeline::operator+=(std::vector<Cipher *> c) {
  for (size_t i = 0; i < c.size(); i++) {
    this->pipeline.push_back(c[i]);
  }
  return *this;
}
CipherPipeline &CipherPipeline::operator=(std::vector<Cipher *> c) {
  this->pipeline.clear();
  for (size_t i = 0; i < c.size(); i++) {
    this->pipeline.push_back(c[i]);
  }
  return *this;
}

std::vector<Cipher *> operator+(Cipher &lhs, Cipher &rhs) {
  std::vector<Cipher *> result;
  result.push_back(&lhs);
  result.push_back(&rhs);
  return result;
}
