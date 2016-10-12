#include <iostream>

#include "Caesar.h"
#include "CipherPipeline.h"
#include "OneTimePad.h"
#include "RowsColumns.h"
#include "ZigZag.h"

/*
   The following main tests the functionality of various ciphers. Intended
   usage:

   make run < input.txt

   The makefile (provided) compiles the code, and "< input.txt"
   redirects file input to direct input (all inputs are read from the
   input file provided)

   Use at your own discretion, and feel free to extend and/or modify in any way.

   This file will be overwritten by Fitchfork if submitted.
 */

// using namespace std;

int main() {
  std::string text = "Hello, World!..";

  const std::string longText =
      "Emily Elizabeth Dickinson was an American poet. Dickinson "
      "was born in Amherst, Massachusetts. Although part of a "
      "prominent family with strong ties to its community, "
      "Dickinson lived much of her life highly introverted.";

  std::string encoded;

  /************** Task 1 ***************/

  Caesar caes;

  encoded = caes.encode(text); // will yield a prompt to enter a positive value;
  // ENTER 0
  // ENTER 98
  // ENTER -3
  // ENTER 3
  std::cout << encoded << std::endl;
  std::cout << caes.decode(encoded) << std::endl;

  caes.setShift(15);
  encoded = caes.encode(text);
  std::cout << encoded << std::endl;
  std::cout << caes.decode(encoded) << std::endl;

  caes.setShift(66);
  encoded = caes.encode(text);
  std::cout << encoded << std::endl;
  std::cout << caes.decode(encoded) << std::endl;

  caes.setShift(94);
  encoded = caes.encode(text);
  std::cout << encoded << std::endl;
  std::cout << caes.decode(encoded) << std::endl;

  std::cout << std::endl;

  std::cout << "Longer text:\n";
  encoded = caes.encode(longText);
  std::cout << encoded << std::endl;
  std::cout << caes.decode(encoded) << std::endl;

  std::cout << std::endl;

  OneTimePad pad(1);
  encoded = pad.encode(text);
  std::cout << encoded << std::endl;
  std::cout << pad.decode(encoded) << std::endl;

  pad.setSeed(2);
  encoded = pad.encode(text);
  std::cout << encoded << std::endl;
  std::cout << pad.decode(encoded) << std::endl;

  pad.setSeed(9999);
  encoded = pad.encode(text);
  std::cout << encoded << std::endl;
  std::cout << pad.decode(encoded) << std::endl;

  std::cout << std::endl;

  std::cout << "Longer text:\n";
  encoded = pad.encode(longText);
  std::cout << encoded << std::endl;
  std::cout << pad.decode(encoded) << std::endl;

  /************** Task 2 ***************/

  std::cout << std::endl;

  RowsColumns rc;
  encoded = rc.encode(text);
  std::cout << encoded << std::endl;
  std::cout << rc.decode(encoded) << std::endl;
  try {
    std::cout << rc.decode(text) << std::endl;
  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  encoded = rc.encode(longText);
  std::cout << encoded << std::endl;
  std::cout << rc.decode(encoded) << std::endl;
  try {
    std::cout << rc.decode(longText) << std::endl;
  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  std::cout << std::endl;

  ZigZag zz;
  encoded = zz.encode(text);
  std::cout << encoded << std::endl;
  std::cout << zz.decode(encoded) << std::endl;

  try {
    std::cout << zz.decode(text) << std::endl;
  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  encoded = zz.encode(longText);
  std::cout << encoded << std::endl;
  std::cout << zz.decode(encoded) << std::endl;

  try {
    std::cout << zz.decode(longText) << std::endl;
  } catch (const char *e) {
    std::cout << e << std::endl;
  }

  /************** Task 3 ***************/

  std::cout << std::endl;

  CipherPipeline pipe;
  pipe += &caes;
  pipe += &pad;

  encoded = pipe.encode(text);
  std::cout << encoded << std::endl;
  std::cout << pipe.decode(encoded) << std::endl;

  std::cout << std::endl;

  encoded = pipe.encode(longText);
  std::cout << encoded << std::endl;
  std::cout << pipe.decode(encoded) << std::endl;

  std::cout << std::endl;

  pipe += rc + zz;
  encoded = pipe.encode(text);
  std::cout << encoded << std::endl;
  std::cout << pipe.decode(encoded) << std::endl;

  pipe = zz + pad;
  encoded = pipe.encode(text);
  std::cout << encoded << std::endl;
  std::cout << pipe.decode(encoded) << std::endl;
  return 0;
}
