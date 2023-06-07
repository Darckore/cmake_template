# cmake template

A template for cmake-based projects tweaked for my needs.
The main goal is to comfortably generate Visual Studio solutions without unnecessary hassle or manual actions.
I don't want to store VS files in a repo, so here we go.

I never tested the thing under anything except VS, but, in theory, it should work for other IDEs/build systems.

It will automatically configure:
* a static libray
* an (optional) executable
* an (optional) test target via gtest

Sources for all these things are auto-collected, no need to modify CMakeLists files manually to add them.
It will also download and link my utils... ahem... let's call it a library, I guess.

The language standard is force-set to the latest version because this is just how I roll.

This template is probably only useful to me, but anyone is welcome to check it out.