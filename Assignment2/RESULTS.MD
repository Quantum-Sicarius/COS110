# Results:

## Task1:
```
Success: resetting default shift value
Success: caesar (small shift), direct access
Success: caesar (small shift), access via SubstitutionCipher
Success: caesar (small shift)
Success: one-time pad, direct access
Success: one-time pad, access via SubstitutionCipher
Success: one-time pad, access via Cipher

Success: setShift (bounds checking)
Success: caesar (large shift), direct access
Success: caesar (large shift), access via SubstitutionCipher
Success: caesar (large shift), access via Cipher
Success: one-time pad
Success: one-time pad, access via SubstitutionCipher
Success: one-time pad, access via Cipher

Success: setShift (bounds checking)
Success: caesar
Success: one-time pad
```
## Task2:
```
Success: rows-columns, full matrix
Success: exception handling on full matrix
Success: zig-zag, full matrix
Success: exception handling on full matrix (zig-zag)
Success: encode zig-zag text with rows-columns

Success: rows-columns, under-full matrix
Success: exception handling on under-full matrix
Success: zig-zag, full matrix
Success: exception handling on under-full matrix (zig-zag)
Success: encode zig-zag text with rows-columns

Success: rows-columns, under-full matrix
Success: exception handling on under-full matrix
Success: zig-zag, full matrix
Success: exception handling on under-full matrix (zig-zag)
Success: encode zig-zag text with rows-columns
```

## Task3:
```
Success: cipher pipeline, +=
Success: cipher pipeline, +=
Failure: cipher pipeline, +=
Failure: cipher pipeline, +=
Success: cipher pipeline encode: =, +
Success: cipher pipeline decode: =, +
Failure: cipher pipeline encode: +=, +
Failure: cipher pipeline encode: +=, +

Success: caesar error handling
Success: cipher pipeline, +=
Success: cipher pipeline, +=
Failure: cipher pipeline, +=
Failure: cipher pipeline, +=
Success: cipher pipeline, =, +
Failure: cipher pipeline encode: +=, +
Success: cipher pipeline decode: +=, +

Success: cipher pipeline, +=
Success: cipher pipeline, +=
Failure: cipher pipeline, +=
Failure: cipher pipeline, +=
Success: cipher pipeline, =, +
Failure: cipher pipeline, +=, +
```
