package leaguestats;

import java.util.ArrayList;
import java.util.function.Function;

public class League {
	private String name;
	private ArrayList<Division> divisions;
	public League(String name) {
		this.name = name;
		divisions = new ArrayList<Division>();
	}
	public String getName() {
		return name;
	}
	public void addDivision(Division div) {
		divisions.add(div);
	}
	public int getNumDivisions() {
		return divisions.size();
	}
	public int getNumTeams() {
		int numTeams = 0;
		for (Division div : divisions) {
			numTeams += div.getNumTeams();
		}
		return numTeams;
	}
	public int getNumGoalsForDivision(String divName) {
		for (Division div : divisions) {
			if (div.getName() == divName) {
				return div.getNumGoals();
			}
		}
		return -1;
	}
	public int getNumGoalsForTeam(String team) {
		return getFromTeam(team, (division -> division.getNumGoalsForTeam(team))).intValue();
	}
	public double getAverageAgeOfTeam(String team) {
		return getFromTeam(team, (division -> division.getAverageAgeOfTeam(team))).doubleValue();
	}
	public Number getFromTeam(String team, Function<Division, Number> divMethod) {
		// Creates a new ArrayList with the same elements as divisions, rather than
		// pointing to the same List so removeIf() doesn't remove elements in divisions.
		ArrayList<Division> filteredDivs = new ArrayList<Division>(divisions);
		filteredDivs.removeIf(div -> divMethod.apply(div).intValue() == -1);
		// If there is still one element left in the List, return
		// the result of applying the method to it, else return -1.
		return filteredDivs.size() > 0 ? divMethod.apply(filteredDivs.get(0)) : -1;
	}
}
