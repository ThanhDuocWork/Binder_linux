import os

include_template = '\n#include "{include}CommandHandler.h"'
element_template = '{{"{str}", std::make_shared<{str}CommandHandler>()}}'

def find_all_folders(target_folder, start_dir):
    all_found_folders = [] 
    for root, dirs, files in os.walk(start_dir):
        for directory in dirs:
            if directory == target_folder:
                folder_path = os.path.join(root, directory)
                all_found_folders.append(folder_path)  
    return all_found_folders

def list_header_files(directory):
    header_files = [file for file in os.listdir(directory) if file.endswith('.h')]
    return header_files

def get_name_cpp_files(directory):
    cpp_files = [file for file in os.listdir(directory) if file.endswith('.cpp')]
    if cpp_files:
        return directory +"/"+ cpp_files[0]

def generate_file(file_name, content):
    
    with open(f"{file_name}", "w") as file:
        file.write(content)
    print(f"Gen file {file_name} successed!")

def list_map_name(list_header):
    found_list_header = []
    for folder_path in list_header:
        files = list_header_files(folder_path)
        if files :
            index_name = files[0].find("Srv")
            class_name = files[0][:index_name + 3:]
            found_list_header.append(class_name)
    return found_list_header

current_folder = os.path.dirname(os.path.abspath(__file__))
directory = current_folder + '/../../../Services/'
target_folder = "Scripts"  

result = find_all_folders(target_folder, directory)
result_name = list_map_name(result)

cpp_content = f"""
#ifndef COMMAND_SERVICE
#define COMMAND_SERVICE
#include <map>
#include <iostream>
#include <memory>"""
for  name in result_name:
    cpp_content += include_template.format(include=name) 
cpp_content += f"""
static const std::map<std::string, std::shared_ptr<ICommandHandler>>
    SERVICE_EXECUTE_TABLE{{  
        """   
for index, name in enumerate(result_name):
    cpp_content += element_template.format(str=name)
    if index != len(result_name) - 1:  
        cpp_content += ',\n\t\t'
cpp_content += f"""   }};
#endif /*COMMAND_SERVICE */
    """
generate_file("../inc/CommandService.h", cpp_content)

CMake_content =f"""
include_directories(
"""
for folder in result:
   CMake_content += '\t' + folder + '\n'
CMake_content += f""")"""

CMake_content +=f"""
set( SOURCE_SCRIPTS
"""
for folder in result:
   CMake_content += '\t' + get_name_cpp_files(folder) + '\n'
CMake_content += f""")"""
generate_file("CMakeLists.txt", CMake_content)