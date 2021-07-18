import { Injectable } from '@angular/core';
import * as faker from 'faker';
import { Note } from '../types/models';

@Injectable({
  providedIn: 'root'
})
export class NotesService {
  notes: Note[];
  currentNote: number;
  constructor() {
    this.notes = this.generateRandomData(10);
  }

  generateRandomData(quantity: number): Note[] {
    const notes: Note[] = [];

    for(let index = 0; index < quantity; index++) {
      // https://www.npmjs.com/package/faker
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

  editNote(title: string, content: string, image: string, noteId: number){
    this.notes[noteId-1].content = content;
    this.notes[noteId-1].title = title;
    this.notes[noteId-1].image = image;
  }

  deleteNote(noteId: number){
    if (noteId-1 > -1) {
      this.notes.splice(noteId-1, 1);
    }
    for (let i = 0; i < this.notes.length; i++) {
      this.notes[i].id = i+1;
    }
  }
}
