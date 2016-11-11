package leaguestats;

import java.util.ArrayList;
import java.util.function.Function;

public class Team {
	private String name;
	private int trophies;
	private ArrayList<Player> squad;
	
	public Team(String name, int trophies) {
		this.name = name;
		this.trophies = trophies;
		squad = new ArrayList<Player>();
	}
	public void addPlayer(Player player) {
		squad.add(player);
	}
	public int getNumGoals() {
		return getFromAllPlayers(player -> player.getGoals());
	}
	public String getName() {
		return name;
	}
	public double getAverageAge() {
		// Must cast to double to get accurate result as both sides of operation are integers.
		return (double) getFromAllPlayers(player -> player.getAge()) / squad.size();
	}
	public int getFromAllPlayers(Function<Player, Integer> getIntFromPlayer) {
		int total = 0;
		for (Player player : squad) {
			total += getIntFromPlayer.apply(player);
		}
		return total;
	}
}
