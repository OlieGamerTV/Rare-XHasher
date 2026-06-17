# Rare-XHasher
This is a command line tool that generates hashes that are used by various Rare-developed Xbox & Xbox 360 titles.

## Purpose
The purpose of this is fairly simple.
Most games made for the Xbox and Xbox 360 era developed by Rare utilize hashed versions of filenames.<br/>
These are used for the filenames for specific groups of assets and, in the case of Banjo-Kazooie: Nuts & Bolts, are also used heavily as references to files.

## Supported Games
A list of supported titles that this can generate hashes for as well as some example filenames to test with.
* Grabbed by the Ghoulies (e.g. "aid_movie_ghoulies_gameselect_house" & "aid_loctext_ghoulies_dialog_dialogs")
* Perfect Dark Zero (e.g. "aid_darkpackage_frontend" & "aid_darkpackage_startup")
* Kameo: Elements of Power (e.g. "FrontEndLevel" & "MysticInterior")
* Viva Pinata (e.g. "aid_xwavebank_pinata_streamingdefault")
* Banjo-Kazooie: Nuts & Bolts (e.g. "aid_bundle_banjox_common" & "aid_xmv_banjox_bootupsequence_1")
* Kinect Sports (e.g. "AMID_BRS_bundle_incubation_olympus_common_bundle_bin") [Untested with Season 2]

## Usage
Usage of the tool is also fairly simple. 
The tool requires two arguments, the hashing argument and the filename of choice.
* For Grabbed by the Ghoulies and Viva Pinata, -base is to be used.
* For Perfect Dark Zero, -dark is to be used.
* For Kameo: Elements of Power, -dol is to be used.
* For Banjo-Kazooie: Nuts & Bolts and Kinect Sports, -typed is to be used.

There is also an additional optional argument, -verbose, which goes between the hash argument and filename.
This will print out the steps done while generating said hash.

## Notice
In regards to Kameo: Elements of Power, the hashing code has only been tested on the *.lvl files.<br/>
