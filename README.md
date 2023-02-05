# HookSpot

This is a simple Spotify CEF Patcher with low maintenance required. Currently, it only supports ARM64 Mach-O binaries.

#### TODO:

- Clear and organize the code;

- Find a better way to block the ADs or implement a way to patch it in updates.

## How to use

- Download this repository.

- Open Keychain Access and click on Certificate Assistant. 

- Then create a certificate with Select Identity-Type as "Self Signed Root", Certificate Type as "Code Signing" and save the certificate token.

- Open main.py and swap the value of the variable `cert` with the certificate token.

- Run the script every time Spotify is updated because the CEF binary will likely be updated every time.

## Credits

Based on:

https://github.com/RDE3/Mac_Spotify_Adblock

https://github.com/ricardobalk/spotify-adblock-macos

Using LIEF Project:

https://github.com/lief-project/LIEF
