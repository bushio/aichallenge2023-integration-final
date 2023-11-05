
import os
import subprocess

WORK_DIR_PATH = "~/aichallenge2023-integration-final/"
CFG_PATH = "scripts/copy_config_path.yaml"
CPD_TABLE = "scripts/cfg_correspondence_table.yaml"
with open(CFG_PATH, "r") as f:
    with open(CPD_TABLE, "w") as fw:
        for line in f.readlines():
            old_cfg_path = line.strip()
            if old_cfg_path[0] == "#":
                continue
            
            cfg_name = os.path.basename(old_cfg_path)
            command = "find src/ -name {}".format(cfg_name)
            output_str = subprocess.run(command, capture_output=True, shell=True).stdout
            result = output_str.decode()
            result = result.split()
            # When there is no file, ignore.
            if len(result) == 0:
                continue
            else:
                fw.write("## ==={}===\n".format(os.path.basename(old_cfg_path)))
                for new_cfg_path in result:
                    fw.write("{} {}{}\n".format(old_cfg_path, WORK_DIR_PATH, new_cfg_path))
            
        

