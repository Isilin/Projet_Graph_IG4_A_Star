
public class Agent {
	private int x;
	private int y;
	public int num;
	
	public Agent(int xIn, int yIn)
	{
		this.x = xIn;
		this.y = yIn;
		this.num = y*43 + x;
	}
	
	public int getX()
	{
		return this.x;
	}
	
	public int getY()
	{
		return this.y;
	}
}
