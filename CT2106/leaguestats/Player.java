package leaguestats;

public class Player {
	private int age, position, goals;
	public Player(int age, int position, int goals) {
		this.age = age;
		this.position = position;
		this.goals = goals;
	}
	public int getGoals() {
		return goals;
	}
	public int getAge() {
		return age;
	}
}
