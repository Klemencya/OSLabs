fallocate -l 50M lofs.img
losetup -a
sudo losetup -f lofs.img
losetup -a | grep lofs.img | awk '{print $1}'
sudo chmod 777 losetup -a | grep lofs.img | awk '{print $1}'
mkfs.ext4 losetup -a | grep lofs.img | awk '{print $1}'
mkdir lofsdisk
sudo mount losetup -a | grep lofs.img | awk '{print $1}' lofsdisk

