# build_install.sh

#!/bin/sh

echo "Creating build directory..."
mkdir -p build && cd build

echo "Running cmake..."
cmake ..

echo "Building..."
cmake --build . --config Release

echo ""
read -p "Do you want to SUDO CMAKE INSTALL libgddr6.a and gddr6 binary to /usr/local? (y/n) " answer

case $answer in
[Yy]*)
	sudo cmake --install . --prefix /usr/local
	echo "Installing..."
	;;
[Nn]*)
	echo "Skipping installation."
	;;
*)
	echo "Please answer y or n."
	;;
esac

cd ..
