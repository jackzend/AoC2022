import os
import pathlib

root = pathlib.Path(r'input')


filelist = []
for filepath in root.rglob('*.txt'):
    file = open(filepath,'r')
    dayname = (filepath.name.split('.'))[0]
    header_file = dayname + '.h'
    print(header_file)
    out = open('input/' + header_file, 'w')
    lines = file.readlines()
    
    concat_lines = ''
    for line in lines:
        concat_lines += line.strip()
        concat_lines += '\\'
        concat_lines += 'n'
    
    header_guard = (dayname + '_H').upper()
    header_lines = ['#ifndef ' + header_guard + '\n', 
                    '#define ' + header_guard + '\n\n',
                    '#include <string_view>\n\n', 
                    'namespace AoC2022{\n', 
                    '   constexpr std::string_view ' + dayname + '_input =' + ' "' 
                    ]
    out.writelines(header_lines)
    out.write(concat_lines)
    out.write('";\n}\n#endif\n')
