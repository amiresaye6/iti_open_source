import { Component } from '@angular/core';
import { ICourse } from '../icourse';
import { CommonModule } from '@angular/common';
import { DiscountPipe } from '../../pipes/discount-pipe';
import { CourseCard } from '../course-card/course-card';

@Component({
  selector: 'app-courses',
  standalone: true,
  imports: [CommonModule, CourseCard],
  templateUrl: './courses.html',
  styleUrl: './courses.css',
})
export class Courses {
  courses: ICourse[];
  categories: string[] = ['all'];
  filteredCourses: ICourse[];

  constructor() {
    this.courses = [
      {
        id: 1,
        title: 'Mastering React: From Zero to Hero',
        instructor: 'Sarah Drasner',
        price: 100,
        seats: 1,
        image:
          'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSkSwPnsBvGSuFxV3hK9aBI5Dn4DHIabjNIPA&s',
        catId: 'web-dev',
      },
      {
        id: 2,
        title: 'Introduction to UI/UX Design',
        instructor: 'Gary Simon',
        price: 35.0,
        seats: 12,
        image:
          'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSa4hBUlAPHX4kRTlITL-L6-iTdkKnrnGmfsg&s',
        catId: 'design',
      },
      {
        id: 3,
        title: 'Python for Data Science',
        instructor: 'Jose Portilla',
        price: 200,
        seats: 2,
        image:
          'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQtf5QHZg4f7SC-fbWlUN9VB8-uou1bNxrdFg&s',
        catId: 'data-science',
      },
      {
        id: 4,
        title: 'Advanced CSS Animations',
        instructor: 'Kevin Powell',
        price: 50,
        seats: 15,
        image:
          'https://i.ytimg.com/vi/SgmNxE9lWcY/hq720.jpg?sqp=-oaymwEhCK4FEIIDSFryq4qpAxMIARUAAAAAGAElAADIQj0AgKJD&rs=AOn4CLDBCfwlw9C6o8bVWq43q2GnBsA2fQ',
        catId: 'web-dev',
      },
      {
        id: 5,
        title: 'Digital Marketing Strategy 2026',
        instructor: 'Neil Patel',
        price: 500,
        seats: 100,
        image:
          'https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQgFIN92SoPkb73hBLbdzR2yKAi5HMbKnjCfA&s',
        catId: 'business',
      },
    ];

    this.courses.forEach((el) => {
      if (!this.categories.includes(el.catId)) {
        this.categories.push(el.catId);
      }
    });

    this.filteredCourses = this.courses;
  }

  get totalValue(): number {
    const pipe = new DiscountPipe();
    return this.courses
      .filter((c) => 'booked' in c && c.booked)
      .reduce((acc, c) => acc + pipe.transform(c.price), 0);
  }

  filterByCategory(event: Event): void {
    const value = (event.target as HTMLSelectElement).value;
    this.filteredCourses =
      value === 'all' ? this.courses : this.courses.filter((c) => c.catId === value);
  }

  bookSeat(id: number): void {
    const course = this.courses.find((c) => c.id === id);
    if (course && course.seats > 0) {
      course.seats--;
      course.booked = true;
    }
  }
}
