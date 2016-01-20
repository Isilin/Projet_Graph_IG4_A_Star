
public class Case {
	public final static int GRASS = 0;
	public final static int FOREST = 1;
	public final static int WATER = 2;
	public final static int WALL = 3;
	public final static int WAY = 4;
	public final static int BRIDGE = 5;
	
	public int type;
	public int crossingTime = -1;
	public int num;
	public int x;
	public int y;
	public int neighborTop = -1;
	public int neighborBottom = -1;
	public int neighborLeft = -1;
	public int neighborRight = -1;
	public int cost = 0;
	public int parent = 0;
	
	public Case(int typeIn, int xIn, int yIn)
	{
		this.type = typeIn;
		this.x = xIn;
		this.y = yIn;
		this.num = y*43 + x;
		
		if(typeIn == GRASS){
			this.crossingTime = 20;
		} else if(typeIn == WAY || typeIn == BRIDGE){
			this.crossingTime = 5;
		} else if(typeIn == FOREST){
			this.crossingTime = 70;
		}
		
		if(yIn != 0){
			this.neighborTop = (yIn - 1)*43 + xIn;
		}
		if(yIn != 36){
			this.neighborBottom = (yIn + 1)*43 + xIn;
		}
		if(xIn != 0){
			this.neighborLeft = yIn*43 + xIn - 1;
		}
		if(xIn != 42){
			this.neighborRight = yIn*43 + xIn + 1;
		}
	}
	
	private int costTo(int xIn, int yIn, Case mapIn[])
	{
		if(this.x == xIn && this.y == yIn){
			return 0;
		} else if(this.x > xIn){
			return this.crossingTime + mapIn[this.neighborLeft].costTo(xIn, yIn, mapIn);
		} else if(this.x < xIn){
			return this.crossingTime + mapIn[this.neighborRight].costTo(xIn, yIn, mapIn);
		} else if(this.y > yIn){
			return this.crossingTime + mapIn[this.neighborTop].costTo(xIn, yIn, mapIn);
		} else if(this.y < yIn){
			return this.crossingTime + mapIn[this.neighborBottom].costTo(xIn, yIn, mapIn);
		} else {
			return -1;
		}
	}
	
	public Case visite(Case sourceIn, Case goalIn, Case mapIn[], int parentIn)
	{
		this.cost = this.costTo(sourceIn.x, sourceIn.y, mapIn)
					+ this.costTo(goalIn.x, goalIn.y, mapIn);
		this.parent = parentIn;
		return this;
	}
	
	public int newCost(Case sourceIn, Case goalIn, Case mapIn[])
	{
		return this.costTo(sourceIn.x, sourceIn.y, mapIn)
				+ this.costTo(goalIn.x, goalIn.y, mapIn);
	}
}
