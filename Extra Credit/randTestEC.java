//THis function is also in UrlValidatorTest.java but I was having some issues with my java compiler on flip
//so I also included the extra credit random test for URL validator in it's own file

import java.util.Random;

public void IsValidRandomTest()
{
	//Starting with URL templates
	String validScheme = "http://";
	String validAuthority = "www.google.com";
	String www = "www.";
	String com = ".com";
	String semicolon = ":";
	String validPort = ":80";
	String validPath = "/path";
	String validQuery = "?query=answer";
	
	//Let's run 10,000 runs of port numbers, technically any port number should be valid
	for (int i = 0; i < 10000; i++)
	{
		Random rand = new Random();
		int randomPort = rand.nextInt(65535)+1;
		String port = semicolon + String.valueOf(randomPort);
		
		if (testGeneric(validScheme, validAuthority, port, validPath, validQuery) ==  false)
		{
			System.out.println("Error with testing port");
		}
	}
	
	//Now lets do some random testing for website name, any gibberish name should pass
	for (int i = 0; i < 10000; i++)
	{
	    String charArray = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
		Random rand2 = new Random();
		String validString = "example";
		for (int j = 0; j < 1000; j++)
		{
			int charToUse = rand2.nextInt(charArray.length) + 1;
			String append = charArray.charAt(charToUse);
			String testString = validString + append;
			String authority = www + testString + com;
			
			if (testGeneric(validScheme, authority, port, validPath, validQuery) ==  false)
			{
				System.out.println("Error with testing port");
			}
		}
	}
}
