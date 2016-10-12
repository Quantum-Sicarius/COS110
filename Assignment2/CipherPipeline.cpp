#include "CipherPipeline.h"
#include <iostream>

std::string CipherPipeline::encode(std::string s) {
  std::string result = s;

  for (size_t i = this->pipeline.size(); i--;) {
    result = this->pipeline.at(i)->encode(result);
  }

  return result;
}
std::string CipherPipeline::decode(std::string s) {
  std::string result = s;

  for (size_t i = 0; i < this->pipeline.size(); i++) {
    result = this->pipeline.at(i)->decode(result);
  }

  return result;
}

CipherPipeline &CipherPipeline::operator+=(Cipher *c) {
  this->pipeline.push_back(c);
  return *this;
}
CipherPipeline &CipherPipeline::operator+=(std::vector<Cipher *> c) {
  this->pipeline.insert(std::end(this->pipeline), std::begin(c), std::end(c));

  // for (size_t i = 0; i < c.size(); i++) {
  //  this->pipeline.push_back(c.at(i));
  //}
  return *this;
}
CipherPipeline &CipherPipeline::operator=(std::vector<Cipher *> c) {
  this->pipeline.clear();
  for (size_t i = 0; i < c.size(); i++) {
    this->pipeline.push_back(c.at(i));
  }
  return *this;
}
