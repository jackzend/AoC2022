# AoC2022
My Advent of Code 2022 repository. Written in c++20 and shooting for speed.

## Build the code base
Currently requires a c++20 compliant compiler (I use g++-11). Run `build.sh` to build all days

## Run the code
`python3 run_all.py` will run all the days and show the output. I will expand on this script to do some statistics on my solutions. Time elapsed is total time to run the solution including file I/O (I'm reluctant to just constexpr my input in string_views but I may experiment with that). To run the code without file caching run `sync; echo 3 > /proc/sys/vm/drop_caches` before the solutions to get the most accurate solution time for benchmarking. For many of the solutions, file I/O is the bottleneck so the solutions are much faster when the input is cached. 