import os
import subprocess

CPD_TABLE = "scripts/cfg_correspondence_table.yaml"
with open(CPD_TABLE, "r") as f:
    for line in f.readlines():
        if line[0] == "#":
            continue

        line = line.split()
        old_path = line[0]
        new_path = line[1]
        #command = "git diff {} {}".format(old_path, new_path)
        #output_str = subprocess.run(command, shell=True).stdout
        
        ## Copy config
        command = "cp {} {}".format(old_path, new_path)
        output_str = subprocess.run(command, shell=True)