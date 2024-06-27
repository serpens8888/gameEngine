{ pkgs ? import <nixpkgs> {} }:


pkgs.mkShell {
	buildInputs = with pkgs.buildPackages; [
		SDL2
		wayland
	];

}


