import os
import pathlib

root = pathlib.Path(r'/home/jack-slip/AoC2022/build')


for filepath in root.rglob('AoC2022_day*'):
    if not str(filepath.absolute()).endswith('.dir'):
        cmd = str(filepath.absolute())
        os.system(cmd)