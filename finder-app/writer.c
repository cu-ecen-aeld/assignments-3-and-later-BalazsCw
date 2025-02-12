#include <stdio.h>	// printf()
#include <syslog.h>	// openlog(), syslog()
#include <fcntl.h> 	// open()
#include <unistd.h>	// close(), write()
#include <string.h>	// strlen()

int main(int argc, char *argv[]) {

	int ReturnError = 0;
	const int FileName = 1;
	const int Message  = 2;
	int file;

	openlog("WriterProgram", LOG_PID, LOG_USER);

	if( argc != 3 ) {		
		syslog(LOG_ERR, "Incorrect number of arguments: %d given, expected 2", argc-1);
		closelog();
		return 1;
	}


	file = open(argv[FileName], O_CREAT | O_WRONLY, 0644);

	if( file == -1 ) {
		syslog(LOG_ERR, "Could not open file %s", argv[FileName]);
		ReturnError = 1;
	} else {
		syslog(LOG_DEBUG, "Writing %s to %s", argv[Message], argv[FileName]);
		int res = write( file, argv[Message], strlen(argv[Message]) );
	}

	close(file);
	closelog();

	return ReturnError;
}
