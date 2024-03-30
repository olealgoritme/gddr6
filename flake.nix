{
  description = "Linux based GDDR6/GDDR6X VRAM temperature reader for NVIDIA RTX 3000/4000 series GPUs.";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
  utils.lib.eachDefaultSystem(system:
    let
      pkgs = import nixpkgs { inherit system; };
    in {
      packages.gddr6 = with pkgs; stdenv.mkDerivation {
        pname = "gddr6";
        version = "unstable";

        src = ./.;

        buildInputs = [ cmake ];
        nativeBuildInputs = [ pciutils ];
      };

      packages.default = self.packages.${system}.gddr6;

      devShell = with pkgs; mkShell {
        name = "gddr6";
        nativeBuildInputs = [ cmake pciutils ];
      };
    }
  );
}

