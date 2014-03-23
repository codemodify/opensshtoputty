int injectedCode( int argc, char** argv )
{
	char* openSSHprivateKeyFile;
	char* passPhrase;
	char* outputFileInPuttyFormat;
	const char* errorMessage;
    struct ssh2_userkey* sshKey;
	Filename fileName1;
	Filename fileName2;
	
	
	/************************************************************************/
	/*	openShhKeyToPutty.exe privateKeyFile passPhrase outputFile
	/************************************************************************/
	if( 3 != argc )
	{
		printf( "The correct usage is: openShhKeyToPutty.exe privateKeyFile passPhrase outputFile" );
		return 0;
	}
	
	// getting the parameters we will need
	openSSHprivateKeyFile = argv[0];
	passPhrase= argv[1];
	outputFileInPuttyFormat = argv[2];
	
	// here we use the code from the PuTTy project to load and convert a private key from OpenSSH DSA format to Putty
	errorMessage = 0;
	sshKey = 0;
	
	strcpy(fileName1.path,openSSHprivateKeyFile);
	sshKey = openssh_read( openSSHprivateKeyFile, passPhrase, errorMessage );
	//sshKey = import_ssh2( &fileName1, 3, passPhrase, &errorMessage );
	if( SSH2_WRONG_PASSPHRASE != sshKey )
	{
		strcpy(fileName2.path,outputFileInPuttyFormat);
		ssh2_save_userkey( &fileName2, sshKey, passPhrase );
	}

	return 0;
}