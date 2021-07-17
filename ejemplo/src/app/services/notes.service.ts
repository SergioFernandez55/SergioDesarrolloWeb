import { Injectable } from '@angular/core';
import * as faker from 'faker';

export interface Note {
  id: number;
  title: string;
  content: string;
  createDate: string;
  image: string;
}

@Injectable({
  providedIn: 'root'
})
export class NotesService {
  notes: Note[];
  constructor() {
    this.notes = this.generateRandomData(10);
  }

  generateRandomData(quantity: number): Note[] {
    const notes: Note[] = [];

    for(let index = 0; index < quantity; index++) {
      const newNote: Note = {
        id: index + 1,
        title: faker.commerce.productName(),
        content: faker.lorem.paragraph(10),
        createDate: faker.date.past().toISOString(),
        image: faker.internet.avatar()
      };
      notes.push(newNote);
    }

    return notes;
  }

  getNoteById(id: number): Note {
    return this.notes[id - 1];
  }

  saveNote(title: string, content: string, image: string) {
    const newId = this.notes.length + 1;
    const newNote: Note = {
      id: newId,
      content,
      title,
      image,
      createDate: new Date().toISOString()
    };
    this.notes.push(newNote);
  }
}
