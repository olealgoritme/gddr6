## GDDR6/GDDR6X GPU Memory Temperature Reader for Linux

Reads GDDR6/GDDR6X VRAM memory temperatures from multiple supported NVIDIA GPUs found in a host Linux system.
These findings are based on reverse engineering of the NVIDIA GPU Linux driver.


## Prerequisites

- Kernel boot parameter: iomem=relaxed
```
sudo vim /etc/default/grub
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash iomem=relaxed"
sudo update-grub
sudo reboot
```

- Disabling Secure Boot
  
This can be done in the UEFI/BIOS configuration or using [mokutil](https://wiki.debian.org/SecureBoot#Disabling.2Fre-enabling_Secure_Boot):

```
mokutil --disable-validation
```

Check state with:
```
$ sudo mokutil --sb
SecureBoot disabled
```

## Dependencies
- libpci-dev 
```
sudo apt install libpci-dev -y
```

## Installation (cmake)
```
git clone https://github.com/olealgoritme/gddr6
cd gddr6
./build_install.sh
sudo gddr6
```

## Supported GPUs
- RTX 4090 (AD102)
- RTX 4080 Super (AD103)
- RTX 4080 (AD103)
- RTX 4070 Ti Super (AD103)
- RTX 4070 Ti (AD104)
- RTX 4070 Super (AD104)
- RTX 4070 (AD104)
- RTX 3090 Ti (GA102)
- RTX 3090 (GA102)
- RTX 3080 Ti (GA102)
- RTX 3080 (GA102)
- RTX 3080 LHR (GA102)
- RTX 3070 (GA104)
- RTX 3070 LHR (GA104)
- RTX A2000 (GA106)
- RTX A4500 (GA102)
- RTX A5000 (GA102)
- RTX A6000 (AD102)
- L4 (AD104)
- L40S (AD102)
- A10 (GA102)

![](https://github.com/olealgoritme/gddr6/blob/master/gddr6_use.gif)
