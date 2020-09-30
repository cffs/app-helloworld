# Test for TLS issue

This application is likely to crash due to TLS alignment issues.

Do a `make menuconfig`, and:

- enable the "Linux User Space" platform;
- enable the musl library;
- disable the welcome banner in ukboot library (it does not work at the moment
  with musl).

Do `make`.

The resulting application is very likely to crash on an unaligned `movaps`
instruction.

I suspect the same happens with newlib, but it remains to be tested.
