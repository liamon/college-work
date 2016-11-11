package leaguestats;

import java.util.ArrayList;
import java.util.function.Function;

public class Division {
	private String name;
	private ArrayList<Team> teams;
	
	public Division(String name) {
		this.name = name;
		teams = new ArrayList<Team>();
	}
	public void addTeam(Team team) {
		teams.add(team);
	}
	public int getNumTeams() {
		return teams.size();
	}
	public String getName() {
		return name;
	}
	public int getNumGoals() {
		int numGoals = 0;
		for (Team team : teams) {
			numGoals += team.getNumGoals();
		}
		return numGoals;
	}
	public int getNumGoalsForTeam(String teamName) {
		return getFromTeam(teamName, (team -> team.getNumGoals())).intValue();
	}
	public double getAverageAgeOfTeam(String teamName) {
		return getFromTeam(teamName, (team -> team.getAverageAge())).doubleValue();
	}
	public Number getFromTeam(String teamName, Function<Team, Number> teamMethod) {
		// Creates a new ArrayList with the same elements as teams, rather than
		// pointing to the same List so removeIf() doesn't remove elements in teams.
		ArrayList<Team> filteredTeams = new ArrayList<Team>(teams);
		filteredTeams.removeIf(team -> team.getName() != teamName);
		// If there is still one element left in the List, return
		// the result of applying the method to it, else return -1.
		return filteredTeams.size() > 0 ? teamMethod.apply(filteredTeams.get(0)) : -1;
	}
}
