package message;

import account.Account;

public class DirectMessage extends Message
{
    private Account to;

    public DirectMessage(Account from, Account to, Message repliedTo, String body)
    {
        super(from, repliedTo, body);
        this.to = to;
    }

    @Override
    public String toString()
    {
        return "To: " + to + "\n" + super.toString();
    }
}