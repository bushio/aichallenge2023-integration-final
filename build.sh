rosdep install -y --from-paths src --ignore-src --rosdistro $ROS_DISTRO
colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release

source /home/autoware/aichallenge2023-integration-final/install/setup.bash
