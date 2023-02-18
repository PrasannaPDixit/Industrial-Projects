import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
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
//Project Name : File packer unpacker using Graphical user interface
//Author :       Prasanna Prabhakarrao Dixit
//Date :         13/11/2022
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
    public int Packer(String FolderName, String PackFileName)
    {
        int Counter = 0;
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

                Counter = 0;
                int ret = 0;
                
                String Name;

                for(int i = 0; i < allfiles.length; i++)
                {
                    Name = allfiles[i].getName();
                    if(Name.endsWith(".txt"))
                    {
                        
                        Name = Name + " " + allfiles[i].length();

                        //System.out.println("File Name : "+allfiles[i].getName()+ " with length : "+allfiles[i].length() + " bytes");
                        
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

                
            }
            
            else
            {
                Counter = -1;
                //System.out.println("There is no such folder");
            }
        }
        catch(Exception obj)
        {
            Counter = -1;
            //System.out.println("Exception Occured : "+obj);
        }
        return Counter;
    }
    public int UnPacker(String PackFileName)
    {
        int counter = 0;
        try
        {
            File fobj = new File(PackFileName);

            FileInputStream FISobj = new FileInputStream(fobj);

            int ret = 0;
            counter = 0;

            byte Header[] = new byte[100];

            if(fobj.exists())
            {
                while((ret = FISobj.read(Header,0,100)) > 0)
                {
                    String StrHeader = new String(Header);

                    String Arr[] = StrHeader.split(" ");

                    File robj = new File(Arr[0]);

                    robj.createNewFile();
                    //System.out.println("File created successfully with name : "+Arr[0]);

                    int Size = Integer.parseInt(Arr[1]);

                    byte Buffer[] = new byte[Size];

                    FISobj.read(Buffer,0,Size);
                    FileOutputStream FOSobj = new FileOutputStream(robj);

                    FOSobj.write(Buffer,0,Size);

                    counter++;
                }

                
            }
            else
            {
                //System.out.println("There is no such file...");
                counter = -1;
            }
        }    

        catch(Exception obj)
        {
            counter = -1;
            //System.out.println("Exception occured : "+obj);
        }

        return counter;

    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
class PackUnPack extends WindowAdapter implements ActionListener
{
    public JFrame Mainframe;
    public JButton b1,b2;
    public JTextField t1,t2;
    public JLabel label1, label2,label3;
    public Integer iNo1, iNo2;

    public PackUnPack()
    {
        Mainframe = new JFrame("File Packer-UnPacker");
        Mainframe.setSize(1000,500);

        b1 = new JButton("Pack");
        b2 = new JButton("UnPack");

        t1 = new JTextField();
        t2 = new JTextField();

        label1 = new JLabel();
        label2 = new JLabel();
        label3 = new JLabel();



        b1.setBounds(350,380,100,40);
        b2.setBounds(550,380,100,40);
        t1.setBounds(300,30,400,25);
        t2.setBounds(300,70,400,25);
        label1.setBounds(180,30,90,25);
        label2.setBounds(180,70,110,25);
        label3.setBounds(335,150,400,25);

        Mainframe.getContentPane().setForeground( Color.RED );
        b1.setForeground(Color.BLACK);
        b2.setForeground(Color.BLACK);

        Mainframe.getContentPane().setBackground( Color.BLACK );
        b1.setBackground(Color.PINK);
        b2.setBackground(Color.PINK);
        label1.setForeground(Color.WHITE);
        label2.setForeground(Color.WHITE);
        

        Mainframe.add(b1);
        Mainframe.add(b2);
        Mainframe.add(t1);
        Mainframe.add(t2);
        Mainframe.add(label1);
        Mainframe.add(label2);
        Mainframe.add(label3);

        label1.setText("Folder Name");
        label2.setText("Packed File Name");


        Mainframe.addWindowListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);

        Mainframe.setLayout(null);

        Mainframe.setVisible(true);

    }

    public void windowClosing(WindowEvent obj)
    {
        System.exit(0);
    }

    public void actionPerformed(ActionEvent obj)
    {
        try
        {
            int Counter = 0;
            ZipUnzip zobj = new ZipUnzip();

            String FolderName = t1.getText();
            String PackFileName = t2.getText();

            if(obj.getSource() == b1)
            {
                Counter = zobj.Packer(FolderName,PackFileName);

                if(Counter == -1)
                {
                    label3.setForeground(Color.RED);
                    label3.setText("ERROR : Folder does not exists in current working directory");
                }
                else
                {
                    label3.setForeground(Color.WHITE);
                    label3.setText("Number of Files successfully packed : " + Counter);
                }                
            }
            else if(obj.getSource() == b2)
            {
                Counter = zobj.UnPacker(PackFileName);

                if(Counter == -1)
                {
                    label3.setForeground(Color.RED);
                    label3.setText("ERROR : File does not exists in current working directory");
                }
                else
                {
                    label3.setForeground(Color.WHITE);
                    label3.setText("Number of Files successfully Unpacked : " + Counter);
                }                
            }
        }
        catch(Exception obj1)
        {

        }        
    }
}


class PackerUnPacker_GUI
{
    public static void main(String arg[])
    {
        PackUnPack obj = new PackUnPack();
    }
}