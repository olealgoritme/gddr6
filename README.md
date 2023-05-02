## GDDR6(X) GPU Memory Temperature reader for linux

Reads GDDR6 VRAM memory temperature from an NVIDIA GPU. 
These findings are based on reverse engineering of the NVIDIA GPU Linux driver.

## Needs:
- libpciaccess-dev and libpci-dev 
```
sudo apt install libpciaccess-dev libpci-dev -y
```

- Kernel boot parameter: iomem=relaxed
```
sudo vim /etc/default/grub
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash iomem=relaxed"
sudo update-grub
sudo reboot
```

## Tested
- RTX 4090 (AD102)
- RTX 3090 (GA102)
- RTX 3070 (GA104)

![](https://github.com/olealgoritme/gddr6/blob/master/gddr6_use.gif)
