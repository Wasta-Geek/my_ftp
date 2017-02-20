# my_ftp
[Epitech Project] : 2nd Year

Synopsis
=

A Basic ftp implementing following command:		
USER + username   : Specify user for authentication (here <username> must be equal to Anonymous)	
PASS + password   : Specify password for authentication

CWD  + pathname   : Change working directory	
CDUP              : Change working directory to parent directory

QUIT              : Disconnection



PWD								: Print working directory	

PASV							: Enable "passive" mode for data transfer	
PORT  + host-port	: Enable "active" mode for data transfer

HELP							: List available commands

NOOP							: Do nothing


RETR							: Download file from server to client	
STOR							: Upload file from client to server		
LIST							: List files in the current working directory 	
DELE							: Delete file on the server	

Code Example
=

Usage : ./server port path	
*port : port of communication*		
*path : path where files are stored*
