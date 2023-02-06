# HookSpot

This is a simple Spotify CEF Patcher with low maintenance required. Currently, it only supports ARM64 Mach-O binaries and only blocks ADs.

#### TODO:

- Clear and organize the code;
- Find a better way to block the ADs or implement a way to patch it in updates;
- Implement new and usefull features.

## How to use

- Download this repository;
- Open Keychain Access and click on Certificate Assistant;
- Then create a certificate with Select Identity-Type as "Self Signed Root", Certificate Type as "Code Signing";
- On `config.json` replace the `cert` value with your certificate name;
- Now run the script to apply the patch ( Note: you need to run the script every time Spotify is updated because the CEF binary will likely be updated every time ).

## Credits

Based on:

https://github.com/RDE3/Mac_Spotify_Adblock

https://github.com/ricardobalk/spotify-adblock-macos

Using LIEF Project:

https://github.com/lief-project/LIEF
