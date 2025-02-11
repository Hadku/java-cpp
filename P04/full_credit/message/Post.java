package message;

import account.Account;

public class Post extends Message
{
    public Post(Account from, Group group, Message repliedTo, String body)
    {
        super(from, repliedTo, body);
        this.group = group;
    }

    @Override
    public String toString()
    {
        return "Group: " + group + "\n" + super.toString();
    }

    private Group group;
    
}