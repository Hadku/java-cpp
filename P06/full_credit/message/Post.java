package message;

import account.Account;

public class Post extends Message
{
    public Post(Account from, Group group, Message repliedTo, String body)
    {
        super(from, repliedTo, body);
        this.group = group;
    }

    public post(BufferedReader br, Message repliedTo)
    {
        //////////////////////////////////
    }

    public void save(BufferedWriter bw)
    {
        //////////////////
    }

    @Override
    public String toString()
    {
        return "\nGroup: " + group + "\n" + super.toString();
    }

    private Group group;
    
}