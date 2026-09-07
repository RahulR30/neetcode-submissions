class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        adj = [[] for _ in range(numCourses)]

        for course, prereq in prerequisites:
            adj[prereq].append(course)
            indegree[course] += 1

        q = deque()

        for course in range(numCourses):
            if indegree[course] == 0:
                q.append(course)

        finished = 0

        while q:
            course = q.popleft()
            finished += 1

            for next_course in adj[course]:
                indegree[next_course] -= 1

                if indegree[next_course] == 0:
                    q.append(next_course)

        return finished == numCourses