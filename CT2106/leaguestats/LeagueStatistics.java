package leaguestats;

public class LeagueStatistics {
	private League league;
	public void setLeague(League league) {
		this.league = league;
	}
	public int getNumDivisions() {
		return league.getNumDivisions();
	}
	public int getNumTeams() {
		return league.getNumTeams();
	}
	public int getNumGoalsForDivision(String div) {
		return league.getNumGoalsForDivision(div);
	}
	public int getNumGoalsForTeam(String team) {
		return league.getNumGoalsForTeam(team);
	}
	public double getAverageAgeOfTeam(String team) {
		return league.getAverageAgeOfTeam(team);
	}
}
