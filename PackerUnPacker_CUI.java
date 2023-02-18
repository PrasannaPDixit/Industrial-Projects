import java.io.*;
import java.util.*;
//////////////////////////////////////////////////////////////////////////////////////////////////////
// Steps to follow while programming
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Step1    Understand the problem statement
// Step2    Write an algorithm
// Step3    Decide the programming language 
// Step4    Write the program
// step5    Test the program

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Project Name : File packer unpacker using command user interface
//Author :       Prasanna Prabhakarrao Dixit
//Date :         09/01/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Algorithm
//////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    START
    1. Packing :
        Create one empty file
        Fetch all the related files from folder
        Extract name and actual filesize of each file to be packed
        Create 100 bytes of space for storing filename & filesize
        After the 100 bytes write the data of that file
        Do this similar process for every file
        All the data of all the files will be collected in single file

    2. UnPacking :
        Tokenize the data of packed file and separate the words w.r.t white spaces
        First Word is name of the file
        Second Word is Actual File size
        Fetch the data from file having size of actual file size
        create separate files for each file name & store the respective fetched data     
    End
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////


class ZipUnzip
{
    public void Packer(String FolderName, String PackFileName)
    {
        try
        {
            
            File fobj = new File(FolderName);

            File Packobj = new File(PackFileName);

            Packobj.createNewFile();

            FileOutputStream FOSobj = new FileOutputStream(Packobj); 

            if(fobj.exists())
            {
                File allfiles[] = fobj.listFiles();
                byte Buffer[] = new byte[1024];

                int Counter = 0, ret = 0;
                
                String Name;

                for(int i = 0; i < allfiles.length; i++)
                {
                    Name = allfiles[i].getName();
                    if(Name.endsWith(".txt"))
                    {
                        
                        Name = Name + " " + allfiles[i].length();

                        System.out.println("File Name : "+allfiles[i].getName()+ " with length : "+allfiles[i].length() + " bytes");
                        
                        for(int j = Name.length(); j < 100; j++)
                        {
                            Name = Name + " ";
                        }

                        byte HeaderByte[] = Name.getBytes();

                        FOSobj.write(HeaderByte,0,HeaderByte.length);

                        FileInputStream FISobj = new FileInputStream(allfiles[i]);

                        while((ret = FISobj.read(Buffer)) != -1)
                        {
                            FOSobj.write(Buffer,0,ret);
                        }
                        Counter++;
                    }

                }

                System.out.println("------------Summary------------");
                System.out.println("Number of files scanned : "+allfiles.length);
                System.out.println("Number of Files successfully packed : " + Counter);
            }
            else
            {
                System.out.println("There is no such folder");
            }
        }
        catch(Exception obj)
        {
            System.out.println("Exception Occured : "+obj);
        }
    }
    public void UnPacker(String PackFileName)
    {
        try
        {
            File fobj = new File(PackFileName);

            FileInputStream FISobj = new FileInputStream(fobj);

            int ret = 0, counter = 0;

            byte Header[] = new byte[100];

            if(fobj.exists())
            {
                while((ret = FISobj.read(Header,0,100)) > 0)
                {
                    String StrHeader = new String(Header);

                    String Arr[] = StrHeader.split(" ");

                    File robj = new File(Arr[0]);

                    robj.createNewFile();
                    System.out.println("File created successfully with name : "+Arr[0]);

                    int Size = Integer.parseInt(Arr[1]);

                    byte Buffer[] = new byte[Size];

                    FISobj.read(Buffer,0,Size);
                    FileOutputStream FOSobj = new FileOutputStream(robj);

                    FOSobj.write(Buffer,0,Size);

                    counter++;
                }

                System.out.println(counter+" Files unpacked successfully");

            }
            else
            {
                System.out.println("There is no such file...");
            }
        }    

        catch(Exception obj)
        {
            System.out.println("Exception occured : "+obj);
        }

    }
}


    class PackerUnPacker
    {
        public static void main(String ar[])
        {
            Scanner sobj = new Scanner(System.in);
            ZipUnzip zobj = new ZipUnzip();

            System.out.println("------------Welcome to File Packer-UnPacker CUI Panel------------\n\n");

            System.out.println("Enter 1 if you want to pack the files or 2 if you want to unpack the file");
            int choice = sobj.nextInt();

            if(choice == 1)
            {
                System.out.println("Enter the name of folder you want to pack");
                sobj.nextLine();
                String FolderName = sobj.nextLine();
                
                System.out.println("Enter the name of packed file that you want to create:");
                System.out.println("File will be crated in the current working directory");
                String PackFileName = sobj.nextLine();

                zobj.Packer(FolderName,PackFileName);
            }
            else if(choice == 2)
            {
                sobj.nextLine();
                System.out.println("Enter the filename you want to unpack");
                System.out.println("File will be crated in the current working directory");
                String PackFileName = sobj.nextLine();

                zobj.UnPacker(PackFileName);
            }
            else
            {
                System.out.println("Please enter correct choice");
                return;
            }
        }
        

    }