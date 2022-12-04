import os
import pathlib

root = pathlib.Path(r'/home/jack-slip/AoC2022/build')


filelist = []
for filepath in root.rglob('AoC2022_day*'):
    if not str(filepath.absolute()).endswith('.dir'):
        filelist.append(str(filepath.absolute()))

filelist.sort()
for bin in filelist:
    cmd = str(bin)
    os.system(bin)