import java.util.ArrayList;
import java.util.List;

public class Main {

	final static int map[][] = {	{0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,2,2,3,3,2,2,2,2,3,3,2,2,0,0,0,0,0,0,0,0,0},
									{0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,2,3,3,3,3,3,3,3,3,2,2,0,0,0,0,0,0,0,0,0},
									{0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,2,2,2,2,2,2,2,2,2,2,3,4,4,4,4,3,2,2,2,0,0,0,0,0,0,0,0,0},
									{0,0,0,1,0,1,0,0,0,0,1,0,1,0,2,2,2,2,2,2,2,2,2,2,2,3,4,4,4,4,3,2,2,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,1,0,1,0,1,1,0,1,0,1,0,2,2,3,3,2,3,3,3,3,3,2,3,4,4,4,4,3,2,2,0,0,1,1,1,1,0,0,0,0},
									{0,0,0,1,0,1,0,1,0,0,1,0,1,0,2,2,3,3,3,3,4,4,4,3,3,3,4,4,4,4,3,2,2,2,0,0,1,1,0,0,1,1,1},
									{0,1,0,1,0,1,0,1,1,1,1,0,1,0,2,2,2,3,4,4,4,4,4,4,4,4,4,3,3,3,3,3,2,2,0,0,1,1,1,1,1,1,0},
									{0,1,0,1,0,1,0,0,0,0,0,0,1,0,0,2,2,3,4,4,4,4,4,4,4,3,3,3,2,2,3,3,2,2,0,0,0,0,1,1,1,0,0},
									{1,1,0,1,0,1,1,1,1,1,1,1,1,0,0,2,2,3,4,4,4,4,4,4,4,3,2,2,2,2,2,2,2,0,0,0,0,0,1,1,1,1,0},
									{1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,2,2,3,4,4,4,4,4,4,4,3,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,2,2,3,4,4,4,4,4,4,4,3,2,2,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0},
									{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,2,2,3,4,4,4,4,4,4,4,3,2,2,0,0,0,0,0,2,2,1,1,1,1,1,1,1,0},
									{0,0,0,0,0,1,1,1,0,0,0,0,0,0,2,2,2,3,4,4,3,4,3,4,4,3,2,2,2,0,0,0,0,2,2,2,2,1,1,1,1,1,0},
									{1,1,1,0,0,0,0,0,0,0,4,1,1,0,2,2,3,3,3,3,3,4,3,3,3,3,3,2,2,0,0,0,0,0,2,2,2,1,1,1,1,0,0},
									{1,1,1,1,1,1,1,1,1,1,4,1,1,0,2,2,3,3,2,2,2,5,2,2,2,3,3,2,2,0,0,0,1,1,1,2,1,1,1,1,0,0,0},
									{1,1,1,1,1,1,1,1,1,1,4,1,1,1,2,2,2,2,2,2,2,5,2,2,2,2,2,2,2,0,0,1,1,1,1,2,2,1,1,1,1,0,0},
									{0,0,0,0,0,1,1,1,1,1,4,1,1,1,1,2,2,2,2,0,0,4,0,0,2,2,2,2,0,0,0,0,1,1,2,2,2,2,1,1,1,1,1},
									{0,0,0,0,0,0,0,0,1,1,4,1,1,1,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1},
									{0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
									{0,1,1,1,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,4,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,4,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,1,1,0,2,2,2,0,2,2,0},
									{2,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,4,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,4,1,1,0,0,2,2,2,2,2,0},
									{2,2,2,2,0,0,0,0,0,0,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,4,1,1,1,0,0,2,2,2,0,0},
									{0,2,2,2,2,2,2,0,0,4,4,4,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,4,4,1,1,1,0,0,2,2,0,0},
									{0,0,0,0,2,2,2,2,0,4,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,4,4,1,1,1,1,0,0,0,0},
									{0,0,0,0,0,0,2,2,2,5,2,2,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,4,0,0,1,1,0,0,0,0},
									{0,0,0,0,0,0,0,0,2,5,2,2,2,0,0,0,0,0,0,0,4,4,1,1,1,1,1,1,1,1,0,0,0,0,4,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0,4,0,2,2,2,0,0,0,0,0,4,4,4,4,1,1,1,1,1,1,1,0,0,1,1,4,4,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,4,4,4,4,0,0,2,2,2,2,0,0,0,0,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,4,4,4,4,4,0,0,0},
									{0,0,0,1,1,4,4,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,4,4,4,1,1,1,1,1,1,1,1,1,1,1,0,0,0,4,4,0,0},
									{0,1,1,1,1,4,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,1,1,1,1,1,0,0,0,0,2,2,2,2,2,2,0,0,4,4,4},
									{0,1,1,1,1,4,0,0,0,1,1,1,0,0,0,0,0,2,2,2,0,0,0,0,1,1,1,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0},
									{1,1,1,1,1,4,0,0,1,1,1,1,1,1,0,0,0,0,2,2,0,0,0,0,1,1,1,1,0,0,2,2,2,0,0,0,2,2,2,0,0,0,0},
									{1,1,1,0,4,4,0,0,0,1,1,1,1,1,1,1,0,0,2,2,2,0,0,0,0,1,1,1,1,0,0,2,2,2,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,1,1,0,0,2,2,2,2,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
									{0,0,0,0,4,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
	
	public static void main(String[] args) {
		Goal goal = new Goal(21, 5);
		
		
		Case cases[] = new Case[37*43];
		for(int i = 0 ; i < 43 ; i++){
			for(int j = 0; j < 37; j++){
				cases[j*43 + i] = new Case(map[j][i], i, j);
			}
		}
		
		Agent agents[] = new Agent[13];
		agents[0] = new Agent(4, 7);
		agents[1] = new Agent(9, 31);
		agents[2] = new Agent(22, 31);
		agents[3] = new Agent(29, 2);
		agents[4] = new Agent(30, 18);
		agents[5] = new Agent(31, 27);
		agents[6] = new Agent(41, 7);
		agents[7] = new Agent(40, 10);
		agents[8] = new Agent(42, 18);
		agents[9] = new Agent(40, 20);
		agents[10] = new Agent(42, 22);
		agents[11] = new Agent(35, 34);
		agents[12] = new Agent(2, 0);
		
		for(int i = 0; i < 13; i++){
			String chemin = aStar(cases[agents[i].num], cases[goal.num], cases);
			System.out.println("[" + agents[i].getX() + "|" + agents[i].getY() + "]" + chemin);
		}
		
		System.out.println("Press Enter to continue");
		try{System.in.read();}
		catch(Exception e){}
	}
	
	public static String aStar(Case sourceIn, Case goalIn, Case cases[])
	{
		Case map[] = cases;
		Case source = sourceIn;
		Case goal = goalIn;
		
		String chemin = "";
		List<Integer> toExplore = new ArrayList<Integer>();
		List<Integer> explored = new ArrayList<Integer>();
		
		toExplore.add(sourceIn.num);
		source.visite(source, goal, map, -1);
		while(!toExplore.isEmpty() && !toExplore.contains(goal.num)){
			// Récupère u dans toExplore de coût total minimum
			int u = toExplore.get(0);
			if(toExplore.size() > 1){
				for(int i = 1 ; i < toExplore.size() ; i++)
				{
					if(map[toExplore.get(i)].cost < map[u].cost && map[toExplore.get(i)].type != 2 
							&& map[toExplore.get(i)].type != 3){
						u = toExplore.get(i);
					}
				}
			}
			toExplore.remove(new Integer(u));
			
			// u ajouté à la liste explored et les successeurs de u à toExplore
			explored.add(u);
			if(goal.num == u){
				toExplore.clear();
			} else {
				// add bottom
				if(map[u].neighborBottom != -1){
					if(toExplore.contains(map[u].neighborBottom)){
						if(map[map[u].neighborBottom].cost > map[map[u].neighborBottom].newCost(map[u], goalIn, map)){
							map[map[u].neighborBottom].visite(map[u], goalIn, map, u);
						}
					} else {
						if(map[map[u].neighborBottom].type != 2 && map[map[u].neighborBottom].type != 3 
								&& !explored.contains(map[u].neighborBottom)) {
							map[map[u].neighborBottom].visite(map[u], goalIn, map, u);
							toExplore.add(map[u].neighborBottom);
						}
					}
				}
				// add top
				if(map[u].neighborTop != -1){
					if(toExplore.contains(map[u].neighborTop)){
						if(map[map[u].neighborTop].cost > map[map[u].neighborTop].newCost(map[u], goalIn, map)){
							map[map[u].neighborTop].visite(map[u], goalIn, map, u);
						}
					} else {
						if(map[map[u].neighborTop].type != 2 && map[map[u].neighborTop].type != 3 
								&& !explored.contains(map[u].neighborTop)) {
							map[map[u].neighborTop].visite(map[u], goalIn, map, u);
							toExplore.add(map[u].neighborTop);
						}
					}
				}
				// add left
				if(map[u].neighborLeft != -1){
					if(toExplore.contains(map[u].neighborLeft)){
						if(map[map[u].neighborLeft].cost > map[map[u].neighborLeft].newCost(map[u], goalIn, map)){
							map[map[u].neighborLeft].visite(map[u], goalIn, map, u);
						}
					} else {
						if(map[map[u].neighborLeft].type != 2 && map[map[u].neighborLeft].type != 3 
								&& !explored.contains(map[u].neighborLeft)) {
							map[map[u].neighborLeft].visite(map[u], goalIn, map, u);
							toExplore.add(map[u].neighborLeft);
						}
					}
				}
				// add right
				if(map[u].neighborRight != -1){
					if(toExplore.contains(map[u].neighborRight)){
						if(map[map[u].neighborRight].cost > map[map[u].neighborRight].newCost(map[u], goalIn, map)){
							map[map[u].neighborRight].visite(map[u], goalIn, map, u);
						}
					} else {
						if(map[map[u].neighborRight].type != 2 && map[map[u].neighborRight].type != 3 
								&& !explored.contains(map[u].neighborRight)) {
							map[map[u].neighborRight].visite(map[u], goalIn, map, u);
							toExplore.add(map[u].neighborRight);
						}
					}
				}
			}
		}
		
		int u = goal.num;
		while(u != source.num){
			chemin = " >> " + map[u].x + "|" + map[u].y + chemin;
			u = map[u].parent;
		}
		chemin += "\n";
		return chemin;
	}

}
