package message;

import java.io.*;


public class Group
{
    private String name;
    private boolean active;

    public Group(String name)
    {
        if (name == null || name.isEmpty()) 
        {
            throw new IllegalArgumentException("Name cannot be empty");
        }
        this.name = name;
        this.active = true;
    }

    public Group(BufferedReader br) 
        throws IOException
    {
        ////////////////////////////
        name = br.readLine();
        active = Boolean.parseBoolean(br.readLine());

    }

    public void save(BufferedWriter bw) 
        throws IOException
    {
        //////////////////////////
        bw.write(name);
        bw.newLine();
        bw.write(Boolean.toString(active));
        bw.newLine();

    }

    public boolean isActive()
    {
        return active;
    }

    public void disable()
    {
        active = false;
    }

    public void enable()
    {
        active = true;
    }

    @Override
    public String toString()
    {
        String result = name;
        if (!active) 
        {
            result += " inactive";
        }
        return result;
    }
}